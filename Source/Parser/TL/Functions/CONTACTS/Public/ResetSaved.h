#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace CONTACTS
{
class ResetSaved : public TLBaseObject
{
public:
	ResetSaved();
	~ResetSaved();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool result;
};
} //end namespace block
