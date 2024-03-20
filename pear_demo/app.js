'use strict'

//import {addon} from 'bare-whisper'

//console.log(addon)

import {
    runtime, // bare, node, or browser
    platform, // the platform string, ie darwin, win32, etc
    arch, // which arch, arm64, ia32, x64 etc
    isBrowser,
    isBare,
    isNode,
    isLinux,
    isWindows,
    isMac,
    isIOS,
    isAndroid
  } from 'which-runtime'

console.log('isBare :',isBare,'\nsBrowser', isBrowser, '\nisNode', isNode)

document.querySelector('h1').addEventListener('click', (e) => { e.target.innerHTML = `🍐${isBare}`})
