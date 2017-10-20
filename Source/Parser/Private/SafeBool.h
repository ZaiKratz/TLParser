#pragma once

class SafeBoolBase
{
public:
	typedef void (SafeBoolBase::*BoolType)() const;
	void ThisTypeDoesNotSupportComparisons() const {}

	SafeBoolBase() {}
	SafeBoolBase(const SafeBoolBase&) {}
	SafeBoolBase& operator=(const SafeBoolBase&) { return *this; }
	~SafeBoolBase() {}
};

template <typename T = void>
class SafeBool : public SafeBoolBase
{
public:
	operator BoolType() const
	{
		return (static_cast<const T*>(this))->IsValid() ? &SafeBoolBase::ThisTypeDoesNotSupportComparisons : 0;
	}
protected:
	~SafeBool() {}
};

template<>
class SafeBool<void> : public SafeBoolBase
{
public:
	operator BoolType() const
	{
		return IsValid() == true ? &SafeBoolBase::ThisTypeDoesNotSupportComparisons : 0;
	}

protected:
	virtual bool IsValid() const = 0;
	virtual ~SafeBool() {}
};

template <typename T, typename U>
void operator==(const SafeBool<T>& lhs, const SafeBool<U>& rhs)
{
	lhs.ThisTypeDoesNotSupportComparisons();
	return false;
}

template <typename T, typename U>
void operator!=(const SafeBool<T>& lhs, const SafeBool<U>& rhs)
{
	lhs.ThisTypeDoesNotSupportComparisons();
	return false;
}