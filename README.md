
![synapse](https://github.com/coderboyisongithub/Synapse/assets/24197201/3868a6d0-b049-4ea1-bfd1-96559cb8c9f0)
# Synapse
still brewing 🍵

<div align="justify">

## Building instruction

### windows 🪟

- ``git clone --recursive https://github.com/coderboyisongithub/Synapse.git``
- open powershell in same cloned directory as working directory. `powershell` or `pwsh` for powershell 7+
- In powershell run `.\bootstrap.ps1`

This will install dependency and configure Cmake for you and after configuration you will need to build the project using your generator (Xcode,Ninja,Make or Visual studio)

## Matf

Matf is n-dimensional matrix type in synapse. This will become foundation of further implementation in this project. This matrix system is one of the core design of synapse. 

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
Matf right now provides basic matrix operation possible including (+, -,and\*) elementwise scalar division is one its way.

It can be demonstrated with following example
```C++
Matf w4 = w3 * idt;	
Matf sum= w3+w3;	//element wise summation
Matf diff=w3-w3; 	//element wise difference
(w4).print(); 		//multiplication with identity matrix yields matrix itself
```
Thats all for now...

<i>I am looking for contributors for this project</i>

</div>