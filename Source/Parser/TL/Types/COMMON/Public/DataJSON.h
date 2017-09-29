#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DataJSON : public TLBaseObject
{
public:
	DataJSON();
	DataJSON(FString data);

	~DataJSON();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getdata() const
	{
		 return this->data;
	}

private:
	FString data;
};
} //end namespace block
