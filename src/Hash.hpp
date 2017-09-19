#pragma once
#include "Header.hpp"

#include <openssl\md5.h>
#include <openssl\sha.h>

class maelstrom::hash
{
	public:
		static string 
		md5(string sHashContent)
		{
			MD5_CTX ctx;
			MD5_Init(&ctx);
			const char * sTmpHashContent = sHashContent.c_str();
			MD5_Update(&ctx, (const unsigned char *)sTmpHashContent, sHashContent.length());
			unsigned char buf_ctx[MD5_DIGEST_LENGTH];
			MD5_Final(buf_ctx, &ctx);

			char	buf_final[MD5_DIGEST_LENGTH * 2 + 1];
			string	result;

			result.reserve(MD5_DIGEST_LENGTH * 2 + 1);

			for (uint32 j = 0; j < MD5_DIGEST_LENGTH; j++)
			{
				sprintf(buf_final, "%02x", buf_ctx[j]);
				result.append(buf_final);
			}

			return result;
		}

		static string
		sha256(string sHashContent)
		{
			SHA256_CTX ctx;
			SHA256_Init(&ctx);
			const char* sTmpHashContent = sHashContent.c_str();
			SHA256_Update(&ctx, (const unsigned char*)sTmpHashContent, sHashContent.length());
			unsigned char buf_ctx[SHA256_DIGEST_LENGTH];
			SHA256_Final(buf_ctx, &ctx);

			char	buf_final[SHA256_DIGEST_LENGTH * 2 + 1];
			string	result;

			result.reserve(SHA256_DIGEST_LENGTH * 2 + 1);

			for (uint32 j = 0; j < SHA256_DIGEST_LENGTH; j++)
			{
				sprintf(buf_final, "%02x", buf_ctx[j]);
				result.append(buf_final);
			}

			return result;
		}

		static string
		sha512(string sHashContent)
		{
			SHA512_CTX ctx;
			SHA512_Init(&ctx);
			const char* sTmpHashContent = sHashContent.c_str();
			SHA512_Update(&ctx, (const unsigned char*)sTmpHashContent, sHashContent.length());
			unsigned char buf_ctx[SHA512_DIGEST_LENGTH];
			SHA512_Final(buf_ctx, &ctx);

			char	buf_final[SHA512_DIGEST_LENGTH * 2 + 1];
			string	result;

			result.reserve(SHA512_DIGEST_LENGTH * 2 + 1);

			for (uint32 j = 0; j < SHA512_DIGEST_LENGTH; j++)
			{
				sprintf(buf_final, "%02x", buf_ctx[j]);
				result.append(buf_final);
			}

			return result;
		}
};
