#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace PAYMENTS
{
class ClearSavedInfo : public TLBaseObject
{
public:
	ClearSavedInfo();
	ClearSavedInfo(bool credentials, bool info);

	~ClearSavedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getcredentials() const
	{
		 return this->credentials;
	}

	bool Getinfo() const
	{
		 return this->info;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool credentials;
	 bool info;
	bool result;
};
} //end namespace block
