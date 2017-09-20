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
private:
	FString street_line1;
	 FString street_line2;
	 FString city;
	 FString state;
	 FString country_iso2;
	 FString post_code;
};
} //end namespace block
