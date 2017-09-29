#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class UpdateStatus : public TLBaseObject
{
public:
	UpdateStatus();
	UpdateStatus(bool offline);

	~UpdateStatus();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getoffline() const
	{
		 return this->offline;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool offline;
	bool result;
};
} //end namespace block