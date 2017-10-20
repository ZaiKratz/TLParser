#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ReportSpam : public TLBaseObject
{
public:
	ReportSpam();
	ReportSpam(TLBaseObject* peer);

	~ReportSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	bool result;
};
} //end namespace block
