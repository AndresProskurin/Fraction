#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int get_numerator() const
	{
		return numerator_;
	}

	int get_denominator() const
	{
		return denominator_;
	}

	bool operator==(const Fraction& other) const
	{
		return numerator_ == other.numerator_ && denominator_ == other.denominator_;
	}

	bool operator!=(const Fraction& other) const
	{
		return numerator_ != other.numerator_ || denominator_ != other.denominator_;
	}

	bool operator<(const Fraction& other) const
	{
		return numerator_ * other.denominator_ < other.numerator_ * denominator_;
	}

	bool operator>(const Fraction& other) const
	{
		return numerator_ * other.denominator_ > other.numerator_ * denominator_;
	}

	bool operator<=(const Fraction& other) const
	{
		return numerator_ * other.denominator_ <= other.numerator_ * denominator_;
	}

	bool operator>=(const Fraction& other) const
	{
		return numerator_ * other.denominator_ >= other.numerator_ * denominator_;
	}

	Fraction operator+(const Fraction& other) const
	{
		int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
		int new_denominator = denominator_ * other.denominator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator-(const Fraction& other) const
	{
		int new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
		int new_denominator = denominator_ * other.denominator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator*(const Fraction& other) const
	{
		int new_numerator = numerator_ * other.numerator_;
		int new_denominator = denominator_ * other.denominator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator/(const Fraction& other) const
	{
		int new_numerator = numerator_ * other.denominator_;
		int new_denominator = denominator_ * other.numerator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator-() const
	{
		return Fraction(-numerator_, denominator_);
	}

	Fraction operator++()
	{
		numerator_ += denominator_;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp(*this);
		numerator_ += denominator_;
		return temp;
	}

	Fraction operator--()
	{
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction temp(*this);
		numerator_ -= denominator_;
		return temp;
	}

	int gcd(int a, int b) const
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	Fraction should_reduce() const
	{
		int gcd_value = gcd(numerator_, denominator_);
    	return Fraction(numerator_ / gcd_value, denominator_ / gcd_value);
	}

};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	int a {};
	int b {};
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	Fraction f3(a, b);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> b;
	Fraction f4(a, b);

	std::cout << f3.get_numerator() << '/' << f3.get_denominator() << "+" << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (f3 + f4).should_reduce().get_numerator() << '/' << (f3 + f4).should_reduce().get_denominator() << '\n';
	std::cout << f3.get_numerator() << '/' << f3.get_denominator() << "-" << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (f3 - f4).should_reduce().get_numerator() << '/' << (f3 - f4).should_reduce().get_denominator() << '\n';
	std::cout << f3.get_numerator() << '/' << f3.get_denominator() << "*" << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (f3 * f4).should_reduce().get_numerator() << '/' << (f3 * f4).should_reduce().get_denominator() << '\n';
	std::cout << f3.get_numerator() << '/' << f3.get_denominator() << "/" << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (f3 / f4).should_reduce().get_numerator() << '/' << (f3 / f4).should_reduce().get_denominator() << '\n';
	std::cout << "++" << f3.get_numerator() << '/' << f3.get_denominator() << " * " << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (++f3 * f4).should_reduce().get_numerator() << '/' << (f3 * f4).should_reduce().get_denominator() << '\n';
	std::cout << "Значение дроби 1: " << f3.should_reduce().get_numerator() << '/' << f3.should_reduce().get_denominator() << '\n';
	std::cout << f3.get_numerator() << '/' << f3.get_denominator() << "-- * " << f4.get_numerator() << '/' << f4.get_denominator() << " = " << (f3-- * f4).should_reduce().get_numerator() << '/' << (f3 * f4).should_reduce().get_denominator() << '\n';
	std::cout << "Значение дроби 1: " << f3.should_reduce().get_numerator() << '/' << f3.should_reduce().get_denominator() << '\n';
	return 0;
}