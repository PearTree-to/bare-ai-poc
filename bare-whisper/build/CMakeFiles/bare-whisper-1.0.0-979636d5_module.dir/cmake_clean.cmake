file(REMOVE_RECURSE
  "bare-whisper.bare"
  "bare-whisper.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/bare-whisper-1.0.0-979636d5_module.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
