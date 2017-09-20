#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class FaveSticker : public TLBaseObject
{
public:
	FaveSticker();
	FaveSticker(COMMON::InputDocument* id, bool unfave);

	~FaveSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputDocument* id;
	 bool unfave;
	bool result;
};
} //end namespace block
