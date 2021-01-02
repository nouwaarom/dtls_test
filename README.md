# Dtls test code 
This project contains a small demo of dtls using mbedtls

## Security
Generate a self signed certificate using:

When using RSA:
```
openssl req -x509 -nodes -newkey rsa:2048 -keyout key.pem -out cert.pem -days 9000
```

When using ECDSA:
```
openssl ecparam -list_curves
```
```
openssl ecparam -out ec_key.pem -name secp256r1 -genkey 
```
```
openssl req -new -key ec_key.pem -x509 -nodes -days 365 -out cert.pem
```

To choose a safe keylength I have used:
https://www.keylength.com/en/compare/
