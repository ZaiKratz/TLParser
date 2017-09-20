#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace MESSAGES
{
class HideReportSpam : public TLBaseObject
{
public:
	HideReportSpam();
	HideReportSpam(PRIVATE::InputPeer* peer);

	~HideReportSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	bool result;
};
} //end namespace block
