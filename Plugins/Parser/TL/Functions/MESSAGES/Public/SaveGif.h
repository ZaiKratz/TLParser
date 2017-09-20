#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class SaveGif : public TLBaseObject
{
public:
	SaveGif();
	SaveGif(COMMON::InputDocument* id, bool unsave);

	~SaveGif();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputDocument* id;
	 bool unsave;
	bool result;
};
} //end namespace block
