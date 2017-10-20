#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextConcat : public TLBaseObject
{
public:
	TextConcat();
	TextConcat(TArray<TLBaseObject*> texts);

	~TextConcat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Gettexts() const
	{
		 return this->texts;
	}

private:
	TArray<TLBaseObject*> texts;
};
} //end namespace block
