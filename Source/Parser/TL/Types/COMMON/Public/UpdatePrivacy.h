#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdatePrivacy : public TLBaseObject
{
public:
	UpdatePrivacy();
	UpdatePrivacy(TLBaseObject* key, TArray<TLBaseObject*> rules);

	~UpdatePrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getkey() const
	{
		 return this->key;
	}

	TArray<TLBaseObject*>  Getrules() const
	{
		 return this->rules;
	}

private:
	TLBaseObject* key;
	 TArray<TLBaseObject*> rules;
};
} //end namespace block
