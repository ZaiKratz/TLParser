#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/SavedGifs.h"

//begin namespace block
namespace MESSAGES
{
class SavedGifsNotModified : public TLBaseObject
{
public:
	SavedGifsNotModified();
	~SavedGifsNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
