#include "Main.h"
#include <vector>
#include <chrono>
#include <iomanip>

int main()
{
    while (true)
    {
        system("cls");
        std::cout << "1: Verify a card number\n2: Generate a valid Visa card number\n";
        int choice = 0;

        std::cin >> choice;

        if (choice == 1)
        {
            system("cls");
            unsigned long long Number;
            std::cout << "Enter a Credit/Debit Card Number As One Whole Number: " << std::endl;
            std::cin >> Number;

            CardVerifier VerificationData = Number;

            if (!VerificationData.IsValid)
            {
                std::cout << "Invalid Card" << std::endl;
            }
            else
            {
                std::cout << "Card Is Valid\nCard Number: " << VerificationData.CardNumberStr << "\nCard Type: " << VerificationData.CardType << "\nLength: " << VerificationData.CardNumberStr.length() << std::endl;
            }
        }
        else
        {
            unsigned long long Current = 4000000000000000;
            std::vector<unsigned long long> CardNumbers;
            int AmountValidated = 0;
            CardVerifier Verif;

            std::cout << "Generating all valid Visa numbers" << std::endl;

            auto Start = std::chrono::high_resolution_clock::now();

            for (; Current < 4000000050000000; Current++, AmountValidated++)
            {
                Verif = Current;

                if (Verif.IsValid)
                {
                    CardNumbers.push_back(Current);
                }
            }

            auto End = std::chrono::high_resolution_clock::now();
            auto Diff = End - Start;
            double Time = std::chrono::duration_cast<std::chrono::milliseconds>(Diff).count();
            Time /= 1000;

            std::string cmd = "Title " + std::string("Validated: ") + std::to_string(AmountValidated) + std::string(" Numbers in: ") + std::to_string(Time) + std::string(" Seconds");
            system(cmd.c_str());

            for (int i = 0; i < CardNumbers.size(); i++)
            {
                printf("%llu\n", CardNumbers[i]);
            }
        }
        system("pause");
    }
    return 0;
}
