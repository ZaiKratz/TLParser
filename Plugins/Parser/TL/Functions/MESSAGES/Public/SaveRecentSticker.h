#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class SaveRecentSticker : public TLBaseObject
{
public:
	SaveRecentSticker();
	SaveRecentSticker(bool attached, COMMON::InputDocument* id, bool unsave);

	~SaveRecentSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool attached;
	 COMMON::InputDocument* id;
	 bool unsave;
	bool result;
};
} //end namespace block
