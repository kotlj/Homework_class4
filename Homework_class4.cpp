
#include <iostream>

using namespace std;

int destructCounter = 0;
class Human
{
private:
    char* fullName;

public:

    Human()
    {
        fullName = new char[30];
        fullName[29] = '\0';
    }
    Human(char* _fullName)
    {
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; _fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    fullName[i] = _fullName[i];
                }
            }
            if (p == 0)
            {
                fullName = new char[counter + 1];
                fullName[counter] = '\0';
            }
        }
    }
    Human(const char* _fullName)
    {
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; _fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    fullName[i] = _fullName[i];
                }
            }
            if (p == 0)
            {
                fullName = new char[counter + 1];
                fullName[counter] = '\0';
            }
        }
    }
    Human(Human& obj)
    {
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; obj.fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    this->fullName[i] = obj.fullName[i];
                }
            }
            if (p == 0)
            {
                this->fullName = new char[counter + 1];
                this->fullName[counter] = '\0';
            }
        }
    }

    void editName(char* _fullName)
    {
        delete[] fullName;
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; _fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    fullName[i] = _fullName[i];
                }
            }
            if (p == 0)
            {
                fullName = new char[counter + 1];
                fullName[counter] = '\0';
            }
        }
    }
    void editName(const char* _fullName)
    {
        delete[] fullName;
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; _fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    fullName[i] = _fullName[i];
                }
            }
            if (p == 0)
            {
                fullName = new char[counter + 1];
                fullName[counter] = '\0';
            }
        }
    }
    void editName(Human& obj)
    {
        delete[] this->fullName;
        int counter = 0;
        for (int p = 0; p < 2; p++)
        {
            for (int i = 0; obj.fullName[i] != '\0'; i++)
            {
                if (p == 0)
                {
                    counter++;
                }
                else
                {
                    this->fullName[i] = obj.fullName[i];
                }
            }
            if (p == 0)
            {
                this->fullName = new char[counter + 1];
                this->fullName[counter] = '\0';
            }
        }
    }

    void showName()
    {
        cout << fullName << '\n';
    }

    ~Human()
    {
        if (this->fullName != nullptr && destructCounter != 14)
        {
            delete[] fullName;
        }
        destructCounter++;
    }
};

class Apartament
{
private:
    Human* tenats;
    int size;
public:

    Apartament()
    {
        tenats = new Human[1];
        size = 1;
    }
    Apartament(int _size)
    {
        size = _size;
        tenats = new Human[size];
    }
    Apartament(Human* _tenats, int _size)
    {
        size = _size;
        tenats = new Human[size];
        for (int i = 0; i < size; i++)
        {
            tenats[i] = _tenats[i];
        }
    }
    Apartament(Apartament& obj)
    {
        this->size = obj.size;
        this->tenats = new Human[size];
        for (int i = 0; i < size; i++)
        {
            this->tenats[i].editName(obj.tenats[i]);
        }
    }

    void editHuman(char* _fullName, int humanIndx)
    {
        if (humanIndx < size)
        {
            tenats[humanIndx].editName(_fullName);
        }
    }
    void editHuman(const char* _fullName, int humanIndx)
    {
        if (humanIndx < size)
        {
            tenats[humanIndx].editName(_fullName);
        }
    }
    void editHuman(Human& obj, int humanIndx)
    {
        if (humanIndx < size)
        {
            tenats[humanIndx].editName(obj);
        }
    }

    void showHumans()
    {
        for (int i = 0; i < size; i++)
        {
            tenats[i].showName();
        }
    }

    void addHuman(Human& obj)
    {
        Human* tample = new Human[size + 1];
        for (int i = 0; i < size; i++)
        {
            tample[i].editName(tenats[i]);
        }
        tample[size] = obj;
        delete[] tenats;
        tenats = tample;
        size++;
    }
    void delHuman(int indx)
    {
        if (indx < size)
        {
            Human* tample = new Human[size - 1];
            for (int i = 0; i < size; i++)
            {
                if (i < indx)
                {
                    tample[i] = tenats[i];
                }
                else if (i == indx)
                {
                    continue;
                }
                else
                {
                    tample[i - 1] = tenats[i];
                }
            }
            delete[] tenats;
            tenats = tample;
            size--;
        }
    }

    void copyApart(Apartament& obj)
    {
        this->size = obj.size;
        if (this->tenats != nullptr)
        {
            delete[] this->tenats;
        }
        this->tenats = new Human[this->size];
        for (int i = 0; i < size; i++)
        {
            this->tenats[i].editName(obj.tenats[i]);
        }
    }

    Human getHuman(int indx = 0)
    {
        if (indx < this->size)
        {
            return this->tenats[indx];
        }
    }
    int getSize()
    {
        return this->size;
    }

    ~Apartament()
    {
        if (this->tenats != nullptr)
        {
            delete[] this->tenats;
        }
    }
};

class House
{
private:
    Apartament* aparts;
    int numOfAparts;

public:

    House()
    {
        aparts = new Apartament[1];
        numOfAparts = 1;
    }
    House(int _numOfAparts)
    {
        numOfAparts = _numOfAparts;
        aparts = new Apartament[numOfAparts];
    }
    House(Apartament* _aparts, int _numOfAparts)
    {
        numOfAparts = _numOfAparts;
        aparts = new Apartament[numOfAparts];
        for (int i = 0; i < numOfAparts; i++)
        {
            aparts[i] = _aparts[i];
        }
    }
    House(House& obj)
    {
        this->numOfAparts = obj.numOfAparts;
        this->aparts = new Apartament[this->numOfAparts];
        for (int i = 0; i < this->numOfAparts; i++)
        {
            this->aparts[i] = obj.aparts[i];
        }
    }

    void addApart(Apartament& obj)
    {
        Apartament* tample = new Apartament[numOfAparts + 1];
        for (int i = 0; i < numOfAparts; i++)
        {
            tample[i].copyApart(this->aparts[i]);
        }
        tample[numOfAparts].copyApart(obj);
        delete[] this->aparts;
        this->aparts = tample;
        this->numOfAparts++;
    }
    void addHumanToApart(Human& obj, int apartIndx)
    {
        this->aparts[apartIndx].addHuman(obj);
    }
    void delApart(int indx)
    {
        if (indx < numOfAparts)
        {
            Apartament* tample = new Apartament[numOfAparts - 1];
            for (int i = 0; i < numOfAparts; i++)
            {
                if (i < indx)
                {
                    tample[i] = this->aparts[i];
                }
                else if (i == indx)
                {
                    continue;
                }
                else
                {
                    tample[i - 1] = aparts[i];
                }
            }
            delete[] this->aparts;
            aparts = tample;
            numOfAparts--;
        }
    }
    void delHumanFromApart(int apartIndx, int humanIndx)
    {
        if (apartIndx < numOfAparts && humanIndx < aparts[apartIndx].getSize())
        {
            this->aparts[apartIndx].delHuman(humanIndx);
        }
    }
    void copyHouse(House& obj)
    {
        if (this->aparts != nullptr)
        {
            delete[] this->aparts;
        }
        this->numOfAparts = obj.numOfAparts;
        this->aparts = new Apartament[this->numOfAparts];
        for (int i = 0; i < this->numOfAparts; i++)
        {
            this->aparts[i].copyApart(obj.aparts[i]);
        }
    }
    void housCopyApart(Apartament& obj, int indx)
    {
        if (indx < numOfAparts)
        {
            this->aparts[indx].copyApart(obj);
        }
    }
    void houseEditHuman(Human& obj, int apartIndx, int humanIndx)
    {
        if (apartIndx < this->numOfAparts && humanIndx < this->aparts[apartIndx].getSize())
        {
            this->aparts[apartIndx].editHuman(obj, humanIndx);
        }
    }

    Apartament getApart(int indx = 0)
    {
        return this->aparts[indx];
    }
    int getSize()
    {
        return this->numOfAparts;
    }

    void showApart(int indx)
    {
        this->aparts[indx].showHumans();
    }

    ~House()
    {
        if (this->aparts != nullptr)
        {
            delete[] this->aparts;
        }
    }
};

int main()
{
    Human testHuman0("Test");
    Human testHuman1("Another");
    Human testHuman2("Try");
    Apartament testApart0;
    testApart0.editHuman(testHuman0, 0);
    House testHouse;
    testHouse.houseEditHuman(testHuman1, 0, 0);
    testHouse.addApart(testApart0);
    testHouse.addHumanToApart(testHuman2, 1);
    testHouse.showApart(0);
    testHouse.showApart(1);
    House copyTest;
    copyTest.copyHouse(testHouse);
    copyTest.showApart(0);
    copyTest.showApart(1);
}
