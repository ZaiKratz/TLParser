#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class ExportedAuthorization : public TLBaseObject
{
public:
	ExportedAuthorization();
	ExportedAuthorization(int32 id, TArray<uint8> bytes);

	~ExportedAuthorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

private:
	int32 id;
	 TArray<uint8> bytes;
};
} //end namespace block
