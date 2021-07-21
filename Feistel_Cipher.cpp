#include <iostream>
#include <string>
using namespace std;

// char key1[10] = {'1', '0', '1', '0', '1', '1', '1', '0'};
// char key2[10] = {'0', '1', '1', '0', '0', '0', '0', '1'};
// char key2[10] = {'1', '1', '1', '0', '1', '0', '0', '1'};

string key1 = "10101110";
string key2 = "01100001";
string key3 = "11101001";

char XOR(char c1, char c2)
{
    if (c1 == '1' && c2 == '1')
    {
        return '0';
    }
    else if (c1 == '0' && c2 == '0')
    {
        return '0';
    }
    else
    {
        return '1';
    }
}

// Encryption
string encrypt(string str)
{
    // divide the plain text in half using substring built in function
    string L = str.substr(0, str.length() / 2);
    string R = str.substr(str.length() / 2);

    string L1;
    string F1;
    string R1;

    for (int i = 0; i < 3; i++)
    {
        L1 = R;

        for (int j = 0; j < R.length(); j++)
        {
            // F1 += XOR(R[j], key1[j]); , xor operation
            if (i == 0)
            {
                F1 += XOR(R[j], key1[j]);
            }
            else if (i == 1)
            {
                F1 += XOR(R[j], key2[j]);
            }
            else if (i == 2)
            {
                F1 += XOR(R[j], key3[j]);
            }
        }
        for (int k = 0; k < L.length(); k++)
        {
            R1 += XOR(F1[k], L[k]);
        }

        cout << "\nRound " << i + 1;
        cout << "\nRound Function" << i + 1 << " : " << F1;
        cout << "\nL" << i + 1 << " : " << L1;
        cout << "\nR" << i + 1 << " : " << R1;

        L = L1;
        R = R1;
        // string emptied
        F1 = "";
        R1 = "";
    }
    string encrypted_text = R + L;
    return encrypted_text;
}

// Decryption
string decrypt(string str)
{
    // divide the plain text in half using substring built in function
    string L = str.substr(0, str.length() / 2);
    string R = str.substr(str.length() / 2);

    string L1;
    string F1;
    string R1;

    for (int i = 0; i < 3; i++)
    {
        L1 = R;

        for (int j = 0; j < R.length(); j++)
        {
            // F1 += XOR(R[j], key1[j]); , xor operation
            if (i == 0)
            {
                F1 += XOR(R[j], key3[j]);
            }
            else if (i == 1)
            {
                F1 += XOR(R[j], key2[j]);
            }
            else if (i == 2)
            {
                F1 += XOR(R[j], key1[j]);
            }
        }
        for (int k = 0; k < L.length(); k++)
        {
            R1 += XOR(F1[k], L[k]);
        }

        cout << "\nRound " << i + 1;
        cout << "\nRound Function" << i + 1 << " : " << F1;
        cout << "\nL" << i + 1 << " : " << L1;
        cout << "\nR" << i + 1 << " : " << R1;

        L = L1;
        R = R1;
        // string emptied
        F1 = "";
        R1 = "";
    }
    string decrypted_text = R + L;
    return decrypted_text;
}

int main()
{
    string plain_text;
    cout << "plain_text: ";
    cin >> plain_text;

    cout << "\nkey1: " << key1;
    cout << "\nkey2: " << key2;
    cout << "\nkey3: " << key3;

    string cipher_text = encrypt(plain_text);
    cout << "/nEncryption : " << cipher_text;

    string decrypted_text = decrypt(cipher_text);
    cout << "\nDecryption : " << decrypted_text;
}

// OUTPUT
// plain_text: 1000100010001110

// key1: 10101110
// key2: 01100001
// key3: 11101001
// Round 1
// Round Function1 : 00100000
// L1 : 10001110
// R1 : 10101000
// Round 2
// Round Function2 : 11001001
// L2 : 10101000
// R2 : 01000111
// Round 3
// Round Function3 : 10101110
// L3 : 01000111
// R3 : 00000110/nEncryption : 0000011001000111
// Round 1
// Round Function1 : 10101110
// L1 : 01000111
// R1 : 10101000
// Round 2
// Round Function2 : 11001001
// L2 : 10101000
// R2 : 10001110
// Round 3
// Round Function3 : 00100000
// L3 : 10001110
// R3 : 10001000
// Decryption : 1000100010001110
