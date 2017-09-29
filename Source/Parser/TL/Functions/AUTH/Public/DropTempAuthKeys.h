#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class DropTempAuthKeys : public TLBaseObject
{
public:
	DropTempAuthKeys();
	DropTempAuthKeys(TArray<unsigned long long> except_auth_keys);

	~DropTempAuthKeys();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<unsigned long long>  GetExceptAuthKeys() const
	{
		 return this->except_auth_keys;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TArray<unsigned long long> except_auth_keys;
	bool result;
};
} //end namespace block
