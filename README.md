
![synapse](https://github.com/coderboyisongithub/Synapse/assets/24197201/3868a6d0-b049-4ea1-bfd1-96559cb8c9f0)
# Synapse
still brewing 🍵(9th october,2025: vcpkg port are out of date, currently may not compile)

<div align="justify">

## Building instruction


### windows (x64) 🪟
<details>

- ``git clone --recursive https://github.com/coderboyisongithub/Synapse.git``
- Open powershell in same cloned directory as working directory. `powershell` or `pwsh` for powershell 7+
- In powershell run `.\bootstrap.ps1`
- Wait for terminal to ask for target generators.


<i>Total build will take time(about three spotify music)</i>

</details>
This will install dependency and configure Cmake for you and after configuration you will need to build the project using your generator (Xcode,Ninja,Make or Visual studio)




### Linux (x64) 💽
<details>

Getting your system ready first.
```bash
sudo apt install cmake zip wget curl ninja-build build-essential pkg-config autoconf
```
```bash
sudo apt install clang libc++-dev libc++abi-dev
```

- ``git clone --recursive https://github.com/coderboyisongithub/Synapse.git``
- Open terminal in same cloned directory as working directory.
- It has bootstrap script for to ensure one click build. 
- First change permission of bootstrap `chmod +x bootstrap-linux.sh`
- `./bootstrap-linux.sh`
- Wait for terminal to ask for target generators.

<i>Total build will take time(about three spotify music)</i>

</details>

This will install dependency and configure Cmake for you and after configuration you will need to build the project using your generator


## Matf

Matf is n-dimensional matrix type in synapse. This is foundation for further implementation in this project. This matrix system is one of the core design of synapse. 

A Matf can be instantiated using initializer list right now. further work is on the way.
Lets create a 2x2 matrix and an 2x2 identity matrix
```C++

	Matf w3{ {1,1},{1,1} };
	Matf idt{ {1,0},{0,1} };

```
To see the result Matf has `print` function.
```C++
w1.print("This is a weight matrix"); // print with a message
idt.print(); //print without message.
```
Matf right now provides basic matrix operation possible including (+, -,and\*) element wise scalar division is one its way.

It can be demonstrated with following example
```C++
Matf w3{ {1,1},{1,1} };
Matf idt{ {1,0},{0,1} };
//w2.print("weight02");
Matf w4 = w3;



w3.print("matrix w3");
w4.print("matrix w4 copy-w3");
Matf w5 = std::move(w3);

w5.print("matrix w5 move-w3");

(idt - idt).print("diff idt ");

(idt + idt).print("sum idt");
(idt * idt).print("mul idt");

//w3.print("w3 after moved");// this will trigger error as w3 has been moved to w5;

```
UPDATE: Matf implements move semantics on operators. Results are moved instead of being copied, avoiding expensive copy constructor call.

Thats all for now...

<i>I am looking for contributors for this project</i>

</div>
