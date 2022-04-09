#include <iostream>

int main()
{
    int nfat_milksolids, milk_fat;
    std::cin >> nfat_milksolids >> milk_fat;
    int milk_solids = nfat_milksolids + milk_fat;

    std::cout << (
        milk_solids >= 15 && milk_fat >= 8 ? 1
        : milk_solids >= 10 && milk_fat >= 3 ? 2
        : milk_solids >= 3 ? 3
        : 4
    ) << std::endl;
}