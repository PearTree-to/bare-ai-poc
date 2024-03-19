const path = require('path');
const fs = require('fs');
const { createTranslator, generateText} = require("./whisper-tiny-bare/binding");

const rootDirectory = './'; // if you change the root directory add this
const usingForTVM = 'metal'; // change this as you use this in your system
const directoryPath = 'data/audio_bin'; // change the bin file path

const modelDir = path.join(rootDirectory, 'dist/libs/whisper-tiny');
const sharedObjectPath = path.join(modelDir, 'whisper-tiny.so');

const translator = createTranslator(modelDir, sharedObjectPath, usingForTVM);

// fs.readdir(directoryPath, (err, files) => {
//   if (err) {
//     console.error('Error reading directory:', err);
//     return;
//   }
  
//   const filteredFiles = files.filter(file => file.endsWith('.bin'));
//   filteredFiles.forEach(filePath => {
//     const startTime = new Date();
//     const generatedText = generateText(translator, path.join(rootDirectory,`${directoryPath}/${filePath}`));
//     const endTime = new Date();
//     console.log('\nFile Name :', filePath, '\nTranscript :', generatedText, '\nTime :', `${(endTime - startTime)/1000} S`)
//   });
// });
