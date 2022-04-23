// https://leetcode.com/problems/stock-price-fluctuation/

import java.util.Comparator;
import java.util.HashMap;
import java.util.TreeMap;

class StockPrice {
  // Keeps track of the number of timestamps a particular price exists for.
  // Also maintains the sorted ordering of these prices.
  TreeMap<Integer, Integer> price_count;
  // Maps a timestamp to the stock price at that time.
  HashMap<Integer, Integer> ts_price;
  // Keeps track of the latest time stamp we have seen.
  int latestTimestamp;
  // Keeps track of the price at the latest time stamp.
  int latestPrice;

  public StockPrice() {
    // Price count should be sorted in ascending order of keys (default behaviour).
    this.price_count = new TreeMap<>(Comparator.comparingInt(Integer::intValue));
    this.ts_price = new HashMap<>();
    this.latestTimestamp = -1;
    this.latestPrice = -1;
  }

  public void update(int timestamp, int price) {
    if (this.latestTimestamp <= timestamp) {
      this.latestTimestamp = timestamp;
      this.latestPrice = price;
    }

    // Get the previous price that was recorded at that timestamp (if any)
    // If it exists it means we'll need to update the price_count mapping
    // so that in case this is a correction of a previous price we can remove
    // it from the mapping.
    Integer prevPrice = ts_price.get(timestamp);
    // update the price at this timestamp.
    ts_price.put(timestamp, price);

    // if prevPrice existed - it means this is a correction of a previously
    // recorded price. It means we need to remove that older(wrongly recorded)
    // price.
    if (prevPrice != null) {
      // reduce the number of occurrences of this price by 1.
      price_count.put(prevPrice, price_count.get(prevPrice) - 1);
      // if the count becomes 0, we remove the key completely so that
      // it doesn't factor in to our max price or min price lookups.
      if (price_count.get(prevPrice) == 0) {
        price_count.remove(prevPrice);
      }
    }

    // Add the new price to the price_count mapping.
    price_count.put(price, price_count.getOrDefault(price, 0) + 1);
  }

  public int current() {
    return latestPrice;
  }

  public int maximum() {
    return price_count.lastKey();
  }

  public int minimum() {
    return price_count.firstKey();
  }
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice obj = new StockPrice();
 * obj.update(timestamp,price);
 * int param_2 = obj.current();
 * int param_3 = obj.maximum();
 * int param_4 = obj.minimum();
 */