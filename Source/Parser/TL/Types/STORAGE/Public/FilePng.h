#pragma once
#include "Engine.h"

#include "../../../Types/Private/FileType.h"

//begin namespace block
namespace STORAGE
{
class FilePng : public PRIVATE::FileType
{
public:
	FilePng();
	~FilePng();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
