#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputDocument : public TLBaseObject
{
public:
	InputDocument();
	InputDocument(unsigned long long id, unsigned long long access_hash);

	~InputDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
