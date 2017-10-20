#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class ReportPeer : public TLBaseObject
{
public:
	ReportPeer();
	ReportPeer(TLBaseObject* peer, TLBaseObject* reason);

	~ReportPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	TLBaseObject*  Getreason() const
	{
		 return this->reason;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 TLBaseObject* reason;
	bool result;
};
} //end namespace block
