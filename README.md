## Resource Manager

`Resource Manager` is a single C++ file that transforms files into C++ code, generating:

```
constexpr unsigned int file_array[];
constexpr unsigned int file_size;
```


## Usage

```
ResMan <res folder>
```

The result will be a recursive copy of all folders inside `<res_folder>`, stored in `<res_folder>/c` as .h (C++ headers) and in `<res_folder>/all_res.hpp`.

## Supported Extensions 
 - .png
 - .wav