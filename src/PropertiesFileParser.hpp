#ifndef _CONFIG_PARSER_H_
#define _CONFIG_PARSER_H_

#include "common.hpp"
#include <map>

namespace kocmoc
{
	namespace util
	{
		typedef std::map<string, string> PropertiesCache;

		/**
		 * parse the config file and provide the app with the config values. Singleton
		 */

		/** define the path to the config file */
		#define CONFIG_PARSER_FILE_PATH "kocmoc.properties"

		class PropertiesFileParser
		{
		public:
			/**
			 * Get the singleton instance
			 */
			static PropertiesFileParser& GetInstance(void);

			/**
			 * parse the config file. Make sure to call this method bevore accessing
			 * any public configuration parameters.
			 *
			 * @return true iff parsinf succeeds. 
			 */
			bool parse(void);

			~PropertiesFileParser(void);

			/**
			 * Get a property with the given name.
			 */
			void getProperty(string name, string* value);
			void getProperty(string name, int* value);
			void getProperty(string name, float* value);
			void getProperty(string name, bool* value);

			/**
			 * Dump the cache to stdout for debugging
			 */
			void dumpCache(void);

		private:
				PropertiesFileParser(void);
				PropertiesFileParser(const PropertiesFileParser &cc);

				bool isspacesonly(const string& line);
				void getnextline(std::istream& is, string& line);

				PropertiesCache cache;
		};
	}
}
#endif
