#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace COMMON
{
class InputDocumentEmpty : public TLBaseObject
{
public:
	InputDocumentEmpty();
	~InputDocumentEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
