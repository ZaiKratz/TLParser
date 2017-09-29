#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFileLocation.h"

//begin namespace block
namespace COMMON
{
class InputDocumentFileLocation : public TLBaseObject
{
public:
	InputDocumentFileLocation();
	InputDocumentFileLocation(unsigned long long id, unsigned long long access_hash, int32 version);

	~InputDocumentFileLocation();
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

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 int32 version;
};
} //end namespace block
