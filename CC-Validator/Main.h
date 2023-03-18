#pragma once
#include <iostream>
#include <string>

class CardVerifier
{
public:
    CardVerifier()
    {

    }

    CardVerifier(unsigned long long CardNumber)
    {
        this->CardNumber = CardNumber;
        this->CardNumberStr = std::to_string(CardNumber);
        this->CardNumberLength = this->CardNumberStr.length();
        this->DoVerification();
    }

    int GetSumOddPlace()
    {
        int Sum = 0;

        for (int idx = CardNumberLength - 1; idx >= 0; idx -= 2)
        {
            Sum += (this->CardNumberStr[idx] - (int)'0');
        }

        return Sum;
    }

    int GetEvenDoubled()
    {
        int Sum = 0;

        for (int idx = CardNumberLength - 2; idx >= 0; idx -= 2)
        {
            int Numb = (this->CardNumberStr[idx] - (int)'0') * 2;
            if (Numb > 9)
            {
                Sum += ((Numb / 10 + Numb % 10));
                continue;
            }

            Sum += Numb;
        }
        return Sum;
    }

    bool TestChecksum()
    {
        if (((GetSumOddPlace() + GetEvenDoubled()) % 10) == 0)
            return true;

        return false;
    }

    void GetCardType()
    {
        int FirstDigit = this->CardNumberStr.at(0) - (int)'0';
        this->CardType = "Invalid";

        if (FirstDigit == 4)
        {
            this->CardType = "Visa";
        }
        else if (FirstDigit == 5)
        {
            this->CardType = "Master Card";
        }
        else if (FirstDigit == 3)
        {
            if ((this->CardNumberStr.at(1) - (int)'0') == 7)
            {
                this->CardType = "American Express";
            }
            else
            {
                this->CardType = "Invalid";
            }
        }
        else if (FirstDigit == 6)
        {
            this->CardType = "Discover";
        }
    }

    void DoVerification()
    {
        GetCardType();
        int Size = this->CardNumberStr.length();

        if (!TestChecksum())
        {
            this->IsValid = false;
            this->ChecksumFailed = false;
            return;
        }
        if (this->CardType == "Invalid")
        {
            this->IsValid = false;
            return;
        }
        if (!(Size >= 13 && Size <= 16))
        {
            this->IsValid = false;
            return;
        }

        this->IsValid = true;
    }

    unsigned long long CardNumber = 0;
    std::string CardType = "Invalid";
    std::string CardNumberStr = "Not Set";
    int CardNumberLength = 0;
    bool IsValid = false;
    bool ChecksumFailed = false;
};