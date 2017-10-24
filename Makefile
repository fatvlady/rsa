key_generation:
	g++ -O2 -std=c++14 program_key_generation.cpp -o key_generation

encryption:
	g++ -O2 -std=c++14 program_encryption.cpp -o encryption

sign:
	g++ -O2 -std=c++14 program_sign.cpp -o sign

secure_send:
	g++ -O2 -std=c++14 program_secure.cpp -o secure_send
