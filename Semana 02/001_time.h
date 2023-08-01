#ifndef TIME_H // Inclua esse bloco apenas se TIME_H não está definido
#define TIME_H // Na primeira inclusão, defina TIME_H para que este bloco não seja incluído mais de uma vez

class Time
{
private:      // Seção Privada
  int hour;   // 0 - 23
  int minute; // 0 - 59
  int second; // 0 - 59

public: // Seção Pública
  Time(int hour = 0, int minute = 0, int second = 0);
  int getHour() const;
  int getMinute() const;
  int getSecond() const;
  void setHour(int hour);
  void setMinute(int minute);
  void setSecond(int second);
  void print() const;
  void nextSecond();
};

#endif // Final do bloco #ifndef