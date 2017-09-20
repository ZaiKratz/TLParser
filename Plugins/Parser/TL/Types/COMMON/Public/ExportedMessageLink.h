#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ExportedMessageLink : public TLBaseObject
{
public:
	ExportedMessageLink();
	ExportedMessageLink(FString link);

	~ExportedMessageLink();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString link;
};
} //end namespace block
