# DllHijacks
Just a small repo containing various DLL hijacks

# BasicCmd Compilation

```
x86_64-w64-mingw32-gcc mal.c -shared -o mal.dll
```

# ReverseShell Compilation

Ensure to configure the ATTACKER\_IP and ATTACKER\_PORT defines, otherwise it won't compile

```
x86_64-w64-mingw32-gcc mal.c -shared -lws2_32 -o mal.dll
```
