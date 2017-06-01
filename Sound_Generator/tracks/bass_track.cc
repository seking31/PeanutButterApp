#include "bass_track.h"

namespace bass_track
{
  void setup_buffers(int total_bars, double end_hang_time)
  {
    if (main_buffer_channels == 0)
    {
      main_buffer_channels = 2;
    }

    main_buffer_size = audio_helper::calculate_total_frames(total_bars, end_hang_time);

    main_buffer = new double* [main_buffer_channels];
    bass_track_1 = new double* [main_buffer_channels];
    bass_track_2 = new double* [main_buffer_channels];

    for (int channel=0; channel<main_buffer_channels; channel++)
    {
      main_buffer[channel] = new double [main_buffer_size];
      bass_track_1[channel] = new double [main_buffer_size];
      bass_track_2[channel] = new double [main_buffer_size];

      for (int i=0; i<main_buffer_size; i++)
      {
        main_buffer[channel][i] = 0;
        bass_track_1[channel][i] = 0;
        bass_track_2[channel][i] = 0;
      }
    }
  }

  void test_creation()
  {
    setup_buffers(60, 3.0);
    srand(time(NULL));
    // int** bass_teenth_array = bass_main::generate_test_teenth(0, 35);
    int** chord_arr = chord_gen::one45_hqq(5, 36);

    // int** bass_teenth_array = bass_main::generate_bass_bar(0, 35);
    int** bass_teenth_array1 = music_gen::generate_bar_from_chords(chord_arr, 2);
    int** bass_teenth_array2 = music_gen::generate_bar_from_chords(chord_arr, 2);
    int** bass_teenth_arr_mod1 = music_gen::modify_bar_to_new_mode_or_key(
      bass_teenth_array1, 5, 36, 0, 39, 2
    );
    int** bass_teenth_arr_mod2 = music_gen::modify_bar_to_new_mode_or_key(
        bass_teenth_array2, 5, 36, 0, 39, 2
    );


    for (int i=0; i<16; i++)
    {
      std::cout << "\nNote: " << i << std::endl;
      for (int j=0; j<2; j++)
      {
        std::cout << " " << bass_teenth_array1[i][j];
        std::cout << " compare: " << bass_teenth_arr_mod1[i][j];
      }
      std::cout << std::endl;
    }

    // new int* [16];
    // for (int i=0; i<16; i++)
    // {
    //   bass_teenth_array[i] = new int [2];
    //   bass_teenth_array[i][0] = 35;
    //   bass_teenth_array[i][1] = 1;
    // }
    for (int i=0; i<8; i++)
    {
      if (i%4 == 0)
      {
        bass_writer::write_bass_bar(bass_teenth_array1, i);
      } else if (i%4 == 1) {
        bass_writer::write_bass_bar(bass_teenth_array2, i);
      } else if (i%4 == 2) {
        bass_writer::write_bass_bar(bass_teenth_arr_mod1, i);
      } else {
        bass_writer::write_bass_bar(bass_teenth_arr_mod2, i);
      }
    }

    // int** arrangement = new int* [5];
    // for (int i=0; i<5; i++) {
    //   arrangement[i] = new int [12];
    //   for (int j=0; j<12; j++)
    //   {
    //     arrangement[i][j] = drum_arrangement::drum_arrangement_standard_2[i][j];
    //   }
    // }
    // bass_arrangement::create_tracks_from_arrangement(
    //   arrangement,
    //   arrangement_main::section_length_standard_2,
    //   12
    // );
    for (int channel=0; channel<main_buffer_channels; channel++)
    {
      for (int i=0; i<main_buffer_size; i++)
      {
        main_buffer[channel][i] += bass_track_1[channel][i];
        main_buffer[channel][i] += bass_track_2[channel][i];
      }
    }
  }

  void free_all_track_memory()
  {
    for (int i=0; i<main_buffer_channels; i++)
    {
      delete[] main_buffer[i];
      delete[] bass_track_1[i];
      delete[] bass_track_2[i];
    }
    delete[] main_buffer;
    delete[] bass_track_1;
    delete[] bass_track_2;
  }
}