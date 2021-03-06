'use strict'

const electron = require('electron')
const app = electron.app
const path = require('path')
const BrowserWindow = electron.BrowserWindow
const url = require('url')

let mainWindow = null;

function createWindow() {
  mainWindow = new BrowserWindow({width:1200, height:750})

  mainWindow.loadURL(url.format({
    pathname: path.join(__dirname, 'public/index.html'),
    protocol: 'file:',
    slashes: true
  }))

  mainWindow.webContents.openDevTools()

  mainWindow.on('closed', function () {
    mainWindow = null
  })
}

app.on('ready', createWindow)

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', function () {
  if (mainWindow === null) {
    createWindow()
  }
})
