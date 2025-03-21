## Resource Manager

`Resource Manager` is a single C++ file that transforms files into C++ code, generating:

```
constexpr unsigned int file_array[];
constexpr unsigned int file_size;
```


## Build
```
mkdir build
cd build

cmake ..
make 
```
note that the project single `cpp` file so you dont need  `cmake` or `make`

```
g++ -std=c++23 main.cpp -o ResMan
```
## Usage

```
ResMan <res folder>
```

The result will be a recursive copy of all folders inside `<res_folder>`, stored in `<res_folder>/c` as .h (C++ headers) and in `<res_folder>/all_res.hpp`.

## Supported Extensions 
- .jpeg .jpg .png .gif .bmp .tiff .tif .webp
- .heif .heic .avif .ico .tga .xbm .pbm .pgm .ppm .raw
- .svg .eps .pdf .ai .cdr .swf .emf .wmf .dxf
- .crw .cr2 .cr3 .nef .arw .sr2 .srf .raf .dng .orf
- .pef .rw2 .kdc .erf .mef .srw .psd .xer .hdr .cin .dpx .dds .sgi .rle .jfi

- .wav .aiff .pcm .bwf
- .flac .alac .ape .wv .tta .shn
- .mp3 .aac .ogg .opus .wma .m4a .mp2 .amr
- .mod .xm .s3m .it .mtm .umx
- .mid .midi .rmi
- .dsd .dff .dsf .spx .voc .au .ra .rm .caf

# Note
The file name should be clear from this `char`s `\, /, . , space, !, ", @, #, $, %, &, *, (, ), -, =, +, ;, ~, [, ], {, }` for now at least