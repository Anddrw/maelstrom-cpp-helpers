# maelstrom-cpp-helpers
C++ Helpers with various functions.

Requirements:
> C++11 
> OpenSSL for Hash class

# Random Class (namespace maelstrom::random)
``` c++ 
static uint32 range(uint32 tMin, uint32 tMax)
```
> Will return a random number between tMin and tMax.

``` c++
static char letter(bool bUpper = false)
```
> Will return a random lowercase letter unless bUpper is true.

``` c++ 
static char symbol()
```
> Will return a random symbol.

``` c++
static string alphanumeric(uint32 tSize = 9, bool bAllowUppercase = true, bool bAllowSymbols = true)
```
> Will return a random string with the lenght of tSize.

# DateTime Class (namespace maelstrom::dt)
``` c++
static string current(string format)
```
> Will return the current date/time by the requested format.

# Hash Class (namespace maelstrom::hash)
``` c++
static string md5(string sHashContent)
```
> Will return the md5 hash of sHashContent.

``` c++
static string sha256(string sHashContent)
```
> Will return the sha256 hash of sHashContent.

``` c++
static string sha512(string sHashContent)
```
> Will return the sha512 hash of sHashContent.

# FileSystem Class (namespace maelstrom::filesystem)
``` c++
filesystem(const std::string& filePath)
```
``` c++
bool file_exists(const std::string sFilePath)
```
> Checks if file sFilePath exists.
``` c++
bool file_create(std::string sFilePath)
```
> Will create an empty file.
``` c++
bool append(std::string format, ...)
```
> Appends text to a file.
``` c++
bool clean()
```
> Will clean a file of its contents.
``` c++
bool write(string format, ...)
```
> Will write to a file.
``` c++
string read()
```
> Will read the contents of a file.
``` c++
void replace(std::string& source, const std::string& from, const std::string& to)
```
> Will replace text in a file.

