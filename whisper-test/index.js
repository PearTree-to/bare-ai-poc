const binding = require("./binding");

// console.log(binding)

const res = binding.generate(
    '/Users/abhijit/Desktop/whisper-tiny-translation--transcription-/dist/libs/whisper-tiny',
    '/Users/abhijit/Desktop/whisper-tiny-translation--transcription-/dist/libs/whisper-tiny/whisper-tiny.so',
    'metal',
    '/Users/abhijit/Desktop/whisper-tiny-translation--transcription-/data/audio_bin/mel_data_3D_0.bin'
)

console.log(res)