#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PostAddress : public TLBaseObject
{
public:
	PostAddress();
	PostAddress(FString street_line1, FString street_line2, FString city, FString state, FString country_iso2, FString post_code);

	~PostAddress();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetStreetLine1() const
	{
		 return this->street_line1;
	}

	FString GetStreetLine2() const
	{
		 return this->street_line2;
	}

	FString Getcity() const
	{
		 return this->city;
	}

	FString Getstate() const
	{
		 return this->state;
	}

	FString GetCountryIso2() const
	{
		 return this->country_iso2;
	}

	FString GetPostCode() const
	{
		 return this->post_code;
	}

private:
	FString street_line1;
	 FString street_line2;
	 FString city;
	 FString state;
	 FString country_iso2;
	 FString post_code;
};
} //end namespace block
