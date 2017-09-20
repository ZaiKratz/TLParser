#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PeerSettings : public TLBaseObject
{
public:
	PeerSettings();
	PeerSettings(bool report_spam);

	~PeerSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool report_spam;
};
} //end namespace block
