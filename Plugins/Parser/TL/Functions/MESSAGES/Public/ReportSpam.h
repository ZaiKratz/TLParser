#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace MESSAGES
{
class ReportSpam : public TLBaseObject
{
public:
	ReportSpam();
	ReportSpam(PRIVATE::InputPeer* peer);

	~ReportSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	bool result;
};
} //end namespace block
