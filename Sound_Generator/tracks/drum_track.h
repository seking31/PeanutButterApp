#ifndef DRUM_TRACK
#define DRUM_TRACK

#include <array>
#include <math.h>
#include <iostream>
#include <stdlib.h>

namespace hi_hat_generator
{
  extern int* generate_hi_hat_teenth_array();
  extern int* get_random_hi_hat_standard();
}

namespace kick_generator
{
  extern int* get_random_kick_standard();
}

namespace snare_generator
{
  extern int* get_random_snare_standard();
}

namespace tom_generator
{
  int* generate_tom_teenth_array(int begin_at_teenth);
}

namespace snare_generator
{
  extern int* get_random_snare_standard();
}

namespace hi_hat_writer
{
  extern void write_from_array_at_bar(int teenth_array [16], int bar);
}

namespace kick_writer
{
  extern void write_from_array_at_bar(int teenth_array [16], int bar);
}

namespace tom_writer
{
  extern void write_from_array_at_bar(int teenth_array [16], int bar);
}

namespace snare_writer
{
  extern void write_from_array_at_bar(int teenth_array [16], int bar);
}

namespace crash_writer
{
  extern void write_from_array_at_bar(int teenth_array [16], int bar);
}

namespace audio_helper
{
  extern int calculate_total_frames(int total_bars, double end_hang_time=3);
  extern int calculate_total_frames(int total_bars);
  extern int* silence_hits(int* silence_array, int* teenth_array);
}

namespace drum_arrangement
{
  extern int drum_arrangement_standard_1 [5][7];
  extern int drum_arrangement_standard_2 [5][12];
  extern void create_tracks_from_arrangement(
    int** arrangement,
    int* section_length,
    int total_sections
  );
}

namespace arrangement_main
{
  extern int section_length_standard_1 [7];
  extern int section_length_standard_2 [12];
}

namespace drum_track
{
  double** main_buffer;
  int main_buffer_size;
  int main_buffer_channels;

  double** hi_hat_track;
  double** other_drum_tracks;

  void setup_buffers(int total_bars, double end_hang_time);
  void copy_to_track();
  void free_all_track_memory();
}

#endif
