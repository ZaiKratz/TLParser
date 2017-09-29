#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class ResetAuthorization : public TLBaseObject
{
public:
	ResetAuthorization();
	ResetAuthorization(unsigned long long hash);

	~ResetAuthorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Gethash() const
	{
		 return this->hash;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long hash;
	bool result;
};
} //end namespace block
