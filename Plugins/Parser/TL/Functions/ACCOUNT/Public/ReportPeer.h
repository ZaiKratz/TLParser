#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/ReportReason.h"

//begin namespace block
namespace ACCOUNT
{
class ReportPeer : public TLBaseObject
{
public:
	ReportPeer();
	ReportPeer(PRIVATE::InputPeer* peer, PRIVATE::ReportReason* reason);

	~ReportPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 PRIVATE::ReportReason* reason;
	bool result;
};
} //end namespace block