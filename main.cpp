#include <iostream>
#include <string>

using namespace std;

class Caracteristici {
public:
    string brand;
    int stoc;
    string culoare;

    Caracteristici(string b, int s, string c) : brand(b), stoc(s), culoare(c) {}

    Caracteristici(const Caracteristici& other) : brand(other.brand), stoc(other.stoc), culoare(other.culoare) {}

    void ShowProductInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Stock: " << stoc << endl;
        cout << "Color: " << culoare << endl;
    }

    friend ostream& operator<<(ostream& os, const Caracteristici& obj) {
        os << "Brand: " << obj.brand << "\n";
        os << "Stock: " << obj.stoc << "\n";
        os << "Color: " << obj.culoare << "\n";
        return os;
    }
};

class Face : public Caracteristici {
public:
    string foundation, primer, concealer, powder, contour;

    Face(string f, string p, string c, string pw, string ct)
            : Caracteristici("FaceBrand", 10, "Beige"), foundation(f), primer(p), concealer(c), powder(pw), contour(ct) {}

    void ShowProductInfo() {
        Caracteristici::ShowProductInfo();  // Call base class member function
        cout << "Foundation: " << foundation << "\n";
        cout << "Primer: " << primer << "\n";
        cout << "Concealer: " << concealer << "\n";
        cout << "Powder: " << powder << "\n";
        cout << "Contour: " << contour << "\n";
    }

    friend ostream& operator<<(ostream& os, const Face& obj) {
        os << static_cast<const Caracteristici&>(obj);
        os << "Foundation: " << obj.foundation << "\n";
        os << "Primer: " << obj.primer << "\n";
        os << "Concealer: " << obj.concealer << "\n";
        os << "Powder: " << obj.powder << "\n";
        os << "Contour: " << obj.contour << "\n";
        return os;
    }
};

class Eye : public Caracteristici {
public:
    string mascara, eyeliner, eyeshadow;

    Eye(string m, string e, string es)
            : Caracteristici("EyeBrand", 5, "Black"), mascara(m), eyeliner(e), eyeshadow(es) {}

    void ShowProductInfo() {
        Caracteristici::ShowProductInfo();  // Call base class member function
        cout << "Mascara: " << mascara << "\n";
        cout << "Eyeliner: " << eyeliner << "\n";
        cout << "Eyeshadow: " << eyeshadow << "\n";
    }

    friend ostream& operator<<(ostream& os, const Eye& obj) {
        os << static_cast<const Caracteristici&>(obj);
        os << "Mascara: " << obj.mascara << "\n";
        os << "Eyeliner: " << obj.eyeliner << "\n";
        os << "Eyeshadow: " << obj.eyeshadow << "\n";
        return os;
    }
};

class Lips : public Caracteristici {
public:
    string gloss, liner, lipstick;

    Lips(string g, string l, string ls)
            : Caracteristici("LipsBrand", 8, "Red"), gloss(g), liner(l), lipstick(ls) {}

    Lips(const Lips& other) : Caracteristici(other), gloss(other.gloss), liner(other.liner), lipstick(other.lipstick) {}

    void ShowProductInfo() {
        Caracteristici::ShowProductInfo();  // Call base class member function
        cout << "Gloss: " << gloss << "\n";
        cout << "Liner: " << liner << "\n";
        cout << "Lipstick: " << lipstick << "\n";
    }

    ~Lips() {
        cout << "Destructor  brand: " << brand << endl;
    }

    friend ostream& operator<<(ostream& os, const Lips& obj) {
        os << static_cast<const Caracteristici&>(obj);
        os << "Gloss: " << obj.gloss << "\n";
        os << "Liner: " << obj.liner << "\n";
        os << "Lipstick: " << obj.lipstick << "\n";
        return os;
    }
};

int main() {
    Face faceProduct("FoundationA", "PrimerA", "Beige", "PowderA", "ContourA");
    Eye eyeProduct("MascaraB", "EyelinerB", "EyeshadowB");
    Lips lipsProduct("GlossC", "LinerC", "Red");

    cout << "detalii prod fata:\n";
    faceProduct.ShowProductInfo();

    cout << "\n detalii prod ochi:\n";
    eyeProduct.ShowProductInfo();

    cout << "\n detalii prod buze:\n";
    lipsProduct.ShowProductInfo();

    Lips lipsProduct1("GlossC", "LinerC", "Red");
    Lips lipsProduct2 = lipsProduct1;

    cout << "\nbuze Copy:\n";
    lipsProduct2.ShowProductInfo();

    return 0;
}