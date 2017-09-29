#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace UPLOAD
{
class SaveBigFilePart : public TLBaseObject
{
public:
	SaveBigFilePart();
	SaveBigFilePart(unsigned long long file_id, int32 file_part, int32 file_total_parts, TArray<uint8> bytes);

	~SaveBigFilePart();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetFileId() const
	{
		 return this->file_id;
	}

	int32 GetFilePart() const
	{
		 return this->file_part;
	}

	int32 GetFileTotalParts() const
	{
		 return this->file_total_parts;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long file_id;
	 int32 file_part;
	 int32 file_total_parts;
	 TArray<uint8> bytes;
	bool result;
};
} //end namespace block
