#!/bin/bash
a=A
b=B
echo 12345 > secret_key
./encryption $b.public ./secret_key secret_key_encrypted
./encryption $b.private secret_key_encrypted secret_key_decrypted
