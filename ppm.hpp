#ifndef PPM_HPP
#define PPM_HPP
#include <fstream>
#include <vector>
#include <string>

struct pixel
{
    unsigned __int8 r,g,b;
};

class ppm
{
private:
    std::string format;
    int width;
    int height;
    int maxval;
    std::vector<std::vector<pixel>> grid;
public:
    ppm(std::ifstream& file);
    ~ppm();
    //Getters
    std::string getFormat() const {return this->format;}
    int getWidth() const {return this->width;}
    int getHeight() const {return this->height;}
    int getMaxval() const {return this->maxval;}
    //Print
    void printImage();
    //Efeitos
    void greyScale();
    void negativeRed();
    void negativeGreen();
    void negativeBlue();
    void negative();
    //Salvar
    void saveFile(std::string filename);
};

#endif //PPM_HPP