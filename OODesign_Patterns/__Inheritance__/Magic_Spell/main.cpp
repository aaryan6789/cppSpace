#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Hacker Rank | Magic Spells

You are battling a powerful dark wizard. He casts his spells from a distance, 
giving you only a few seconds to react and conjure your counterspells. 

For a counterspell to be effective, you must first identify what kind of spell 
you are dealing with.
The wizard uses scrolls to conjure his spells, and sometimes he uses some of 
his generic spells that restore his stamina. 
In that case, you will be able to extract the name of the scroll from the spell.
Then you need to find out how similar this new spell is to the spell formulas 
written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body 
of the counterspell function.

FYI : PRE REQUISITE 
Check Dynamic cast to get an idea of how to solve this challenge.

Input Format
The wizard will read t scrolls, which are hidden from you.
Every time he casts a spell, it's passed as an argument to your counterspell function.

Constraints
1 <= t <= 100
1 <= |s| <= 1000 , where s is a scroll name.
Each scroll name, , consists of uppercase and lowercase letters.
Output Format

After identifying the given spell, print its name and power.
If it is a generic spell, find a subsequence of letters that are contained in 
both the spell name and your spell journal. Among all such subsequences, 
find and print the length of the longest one on a new line.

Sample Input
3
fire 5
AquaVitae 999 AruTaVae
frost 7

Sample Output
Fireball: 5
6
Frostbite: 7

Explanation
Fireball and Frostbite are common spell types.
AquaVitae is not, and when you compare it with AruTaVae in your spell journal, you get a sequence: AuaVae
*/

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: 
        int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: 
        int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 

string SpellJournal::journal = "";

// PREREQUISITES:
// Dynamic CASTING : https://www.educative.io/edpresso/what-is-dynamic-casting-in-cpp
// Safely converts pointers and references to classes up, down, and sideways along 
// the inheritance hierarchy.



void counterspell(Spell *spell) {

  /* Enter your code here */
    if (dynamic_cast<Fireball*>(spell)){
        Fireball *fire = dynamic_cast<Fireball*>(spell);
        fire->revealFirepower();
    }
    else if(dynamic_cast<Frostbite*>(spell)){
        Frostbite *frost = dynamic_cast<Frostbite*>(spell);
        frost->revealFrostpower();
        
    }
    else if(dynamic_cast<Thunderstorm*>(spell)){
        Thunderstorm *thunder = dynamic_cast<Thunderstorm*>(spell);
        thunder->revealThunderpower();
    }
    else if(dynamic_cast<Waterbolt*>(spell)) {
        Waterbolt *water = dynamic_cast<Waterbolt*>(spell);
        water->revealWaterpower();
    }
    else{
        // LOWEST COMMON SUBSEQUENCE
        string X = spell->revealScrollName();
        string Y = SpellJournal::read();
        int m = X.length();
        int n = Y.length();

        int **L = new int*[m + 1];
        for (int i = 0; i < m + 1; i++) {
            L[i] = new int[n + 1];
        }
        int i, j;

        /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
        for (i = 0; i <= m; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        cout << L[m][n] << endl;
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}